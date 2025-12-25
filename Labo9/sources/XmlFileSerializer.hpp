#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H

#include <iostream>
#include <fstream>
#include <string>
#include "includes/XmlFileSerializerException.h"
using namespace std;

template<typename T>
class XmlFileSerializer
{
private:
    fstream file;
    string filename;
    char mode;
    string collectionName;

public:
    XmlFileSerializer() = delete;
    XmlFileSerializer(const string& fn, char m, const string& cn = "entities");
    XmlFileSerializer(const XmlFileSerializer& fs) = delete;
    ~XmlFileSerializer();

    string getFilename() const;
    string getCollectionName() const;
    bool isReadable() const;
    bool isWritable() const;

    void write(const T& val);
    T read();

    XmlFileSerializer<T>& operator=(const XmlFileSerializer<T>&) = delete;

    static const char READ = 'R';
    static const char WRITE = 'W';
};

#include "XmlFileSerializer.ipp"
#endif
