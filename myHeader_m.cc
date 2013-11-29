//
// Generated file, do not edit! Created by opp_msgc 4.3 from myHeader.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "myHeader_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(MyHeader);

MyHeader::MyHeader(const char *name, int kind) : cPacket(name,kind)
{
    this->name_var = 0;
    this->ID_var = 0;
    this->year_var = 0;
}

MyHeader::MyHeader(const MyHeader& other) : cPacket(other)
{
    copy(other);
}

MyHeader::~MyHeader()
{
}

MyHeader& MyHeader::operator=(const MyHeader& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void MyHeader::copy(const MyHeader& other)
{
    this->name_var = other.name_var;
    this->ID_var = other.ID_var;
    this->year_var = other.year_var;
}

void MyHeader::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->name_var);
    doPacking(b,this->ID_var);
    doPacking(b,this->year_var);
}

void MyHeader::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->name_var);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->year_var);
}

const char * MyHeader::getName() const
{
    return name_var.c_str();
}

void MyHeader::setName(const char * name)
{
    this->name_var = name;
}

int MyHeader::getID() const
{
    return ID_var;
}

void MyHeader::setID(int ID)
{
    this->ID_var = ID;
}

int MyHeader::getYear() const
{
    return year_var;
}

void MyHeader::setYear(int year)
{
    this->year_var = year;
}

class MyHeaderDescriptor : public cClassDescriptor
{
  public:
    MyHeaderDescriptor();
    virtual ~MyHeaderDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MyHeaderDescriptor);

MyHeaderDescriptor::MyHeaderDescriptor() : cClassDescriptor("MyHeader", "cPacket")
{
}

MyHeaderDescriptor::~MyHeaderDescriptor()
{
}

bool MyHeaderDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MyHeader *>(obj)!=NULL;
}

const char *MyHeaderDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MyHeaderDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MyHeaderDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MyHeaderDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "name",
        "ID",
        "year",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MyHeaderDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "name")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    if (fieldName[0]=='y' && strcmp(fieldName, "year")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MyHeaderDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MyHeaderDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MyHeaderDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MyHeader *pp = (MyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MyHeaderDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MyHeader *pp = (MyHeader *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getName());
        case 1: return long2string(pp->getID());
        case 2: return long2string(pp->getYear());
        default: return "";
    }
}

bool MyHeaderDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MyHeader *pp = (MyHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setName((value)); return true;
        case 1: pp->setID(string2long(value)); return true;
        case 2: pp->setYear(string2long(value)); return true;
        default: return false;
    }
}

const char *MyHeaderDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *MyHeaderDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MyHeader *pp = (MyHeader *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


