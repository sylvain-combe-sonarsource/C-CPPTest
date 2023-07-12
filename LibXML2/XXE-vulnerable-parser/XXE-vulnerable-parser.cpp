#include "libxml/parser.h"

// ruleid: XXE-vulnerable-parser
xmlDocPtr doc = xmlReadFile(xmlFile, nullptr, 0x6);

// ruleid: XXE-vulnerable-parser
xmlDocPtr doc = xmlReadFile(xmlFile, nullptr, XML_PARSE_DTDLOAD | XML_PARSE_NOENT); 

// ok: XXE-vulnerable-parser
xmlDocPtr doc = xmlReadFile(xmlFile, nullptr, 0); // Compliant: safe by default since version 2.9