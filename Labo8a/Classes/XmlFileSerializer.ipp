#include "XmlFileSerializer.hpp"
#include <stdexcept>
#include <sstream>

template<typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, char m, const string& cn)
    : filename(fn), mode(m), collectionName(cn)
{
    if (mode == WRITE) {
        file.open(filename, ios::out | ios::trunc);
        if (!file.is_open())
            throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND,
                                             "Impossible de créer le fichier " + filename);

        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<" << collectionName << ">\n";

    } else if (mode == READ) {
        file.open(filename, ios::in);
        if (!file.is_open())
            throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND,
                                             "Fichier introuvable : " + filename);

        string line;
        getline(file, line); // <?xml ... ?>
        getline(file, line); // <collectionName>
        // Récupération du nom de la collection à partir de la balise
        collectionName = line.substr(1, line.size() - 2); // enlève < et >
    } else {
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED,
                                         "Mode inconnu");
    }
}

template<typename T>
XmlFileSerializer<T>::~XmlFileSerializer() {
    if (mode == WRITE && file.is_open())
        file << "</" << collectionName << ">\n";
    if (file.is_open())
        file.close();
}

template<typename T>
void XmlFileSerializer<T>::write(const T& val) {
    if (mode != WRITE)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED,
                                         "Ecriture interdite en mode READ");
    file << val << "\n";
}

template<typename T>
T XmlFileSerializer<T>::read() {
    if (mode != READ)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED,
                                         "Lecture interdite en mode WRITE");

    string line;
    streampos pos = file.tellg();
    if (!getline(file, line))
        throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE,
                                         "Fin de fichier atteinte");

    if (line.find("</" + collectionName + ">") != string::npos)
        throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE,
                                         "Fin de la collection atteinte");

    // Revenir en arrière pour que l'opérateur >> lise l'objet entier
    file.seekg(pos);

    T obj;
    file >> obj;
    return obj;
}

template<typename T>
string XmlFileSerializer<T>::getFilename() const {
    return filename;
}

template<typename T>
string XmlFileSerializer<T>::getCollectionName() const {
    return collectionName;
}

template<typename T>
bool XmlFileSerializer<T>::isReadable() const {
    return mode == READ;
}

template<typename T>
bool XmlFileSerializer<T>::isWritable() const {
    return mode == WRITE;
}
