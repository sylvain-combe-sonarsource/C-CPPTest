#include "xercesc/parsers/SAXParser.hpp"

void bad_code() {
    SAXParser* SAXparser = new SAXParser(); // Noncompliant: by default entities resolution is enabled so SAXParser is not safe
    SAXparser->setDisableDefaultEntityResolution(false); // Noncompliant: enable resolution of entities explicitly

    // ruleid: SAXParser-XXE-vulnerable-parser
    SAXparser->parse(xmlFile);
}

void bad_code2() {
    SAXParser* SAXparser = new SAXParser(); // Noncompliant: by default entities resolution is enabled so SAXParser is not safe

    // ruleid: SAXParser-XXE-vulnerable-parser
    SAXparser->parse(xmlFile);
}

void good_code() {
    SAXParser* SAXparser = new SAXParser(); // Compliant: entities resolution is disabled so SAXParser is safe
    SAXparser->setDisableDefaultEntityResolution(true);

    // ok: SAXParser-XXE-vulnerable-parser
    SAXparser->parse(xmlFile);
}

