#include "xercesc/parsers/XercesDOMParser.hpp"

void good_code() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    DOMparser->setCreateEntityReferenceNodes(false); 
    // ok: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->setDisableDefaultEntityResolution(false); 
}

void good_code2() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    DOMparser->setCreateEntityReferenceNodes(true); 
    DOMparser->setDisableDefaultEntityResolution(true); 
    // ok: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->parse(xmlFile);
}

void good_code3() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    DOMparser->setDisableDefaultEntityResolution(true);
    DOMparser->setCreateEntityReferenceNodes(true);  
    // ok: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->parse(xmlFile);
}

void bad_code() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    // no entity reference node will be created so the entities will be expanded

    DOMparser->setCreateEntityReferenceNodes(false);
    DOMparser->setDisableDefaultEntityResolution(false);

    // ruleid: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->parse(xmlFile);

    return 0;
}

void bad_code() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    // no entity reference node will be created so the entities will be expanded

    DOMparser->setCreateEntityReferenceNodes(true);
    // todoruleid: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->parse(xmlFile);
    DOMparser->setDisableDefaultEntityResolution(true);

    return 0;
}

void bad_code() {
    XercesDOMParser *DOMparser = new XercesDOMParser();
    // no entity reference node will be created so the entities will be expanded

    // ruleid: XercesDOMParser-XXE-vulnerable-parser
    DOMparser->parse(xmlFile);

    return 0;
}
