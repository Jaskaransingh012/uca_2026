#!/bin/bash

sed -e 's/card=[^"]*/card=XXXX-XXXX-XXXX-XXXX/g;
    s/HTTP\/1\.0/HTTP\/1.1/g;
    /#/d
' sample.txt

