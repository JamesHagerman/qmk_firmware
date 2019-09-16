#!/bin/bash
# This is a hack.
# ./build-keymap-json.sh | node > keymap.json
BEFORE_TOO_MUCH=`cat ./keymap.c | grep -v include | gcc -E -P - | awk 'NF' | grep -zPo '(?s)PROGMEM keymaps.*?};' | head -n -1 | tail -n +2 | sed -r 's/\s+//g' | sed -z 's/,\n\([^[]\)/,\1/g'`

MOSTLY_THERE=`echo "$BEFORE_TOO_MUCH" | sed 's/\[/layers\[/g' | sed 's/=LAYOUT(/ = \[/' | sed -z 's/),\n/\],\n/g' | sed -z 's/"\n/"/g' | sed -z 's/\n)/\n\]/g'`

FIX_LT=`echo "$MOSTLY_THERE" | sed -z 's/\[\n/\["/g' | sed -z 's/\n\],\n/"\]\n/g' | sed -z 's/\n\]\n/\"]\n/g' | sed 's/,/","/g'`

FINALLY=`echo "$FIX_LT" | sed 's/\(LT([[:digit:]]\)","/\1,/g'`

echo "let layers = []"
echo "$FINALLY"
echo "let keymap = {'keyboard':'atreus', 'keymap':'jamis-atreus', 'author':'jamis', 'notes':'', 'layout':'LAYOUT', layers}"
echo "console.log(JSON.stringify(keymap))"


