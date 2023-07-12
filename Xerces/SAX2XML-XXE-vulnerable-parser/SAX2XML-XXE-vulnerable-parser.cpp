#include "xercesc/sax2/SAX2XMLReader.hpp"
// using namespace XMLReaderFactory;
using namespace XMLUni;

void bad_code() {
    SAX2XMLReader* reader = XMLReaderFactory::createXMLReader(); // Noncompliant: by default entities resolution is enabled so SAX2XMLReader is not safe

    reader->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, false); // Noncompliant: enable resolution of entities explicitly

    // ruleid: SAX2XML-XXE-vulnerable-parser
    reader->parse(xmlFile);
}

void bad_code2() {
    SAX2XMLReader* reader = createXMLReader(); // Noncompliant: by default entities resolution is enabled so SAX2XMLReader is not safe

    // ruleid: SAX2XML-XXE-vulnerable-parser
    reader->parse(xmlFile);
}

void good_code() {
    SAX2XMLReader* reader = XMLReaderFactory::createXMLReader();
    reader->setFeature(fgXercesDisableDefaultEntityResolution, true); // Compliant

    // ok: SAX2XML-XXE-vulnerable-parser
    reader->parse(xmlFile);
}

void good_code2() {
    SAX2XMLReader* reader = XMLReaderFactory::createXMLReader();
    reader->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, true); // Compliant

    // ok: SAX2XML-XXE-vulnerable-parser
    reader->parse(xmlFile);
}