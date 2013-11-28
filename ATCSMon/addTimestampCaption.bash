#!/bin/bash
#FILES=$1
for f in "$@"
do
  DIRNAME=`dirname "$f"`
  BASENAME=`basename "$f" | tr -d ' '`

  LAST_MODIFIED_EPOCH=`stat -f "%m" "$f"`
  #echo Epoch is: $LAST_MODIFIED_EPOCH

  TIMESTAMP=`date -r $LAST_MODIFIED_EPOCH +%Y%m%d-%H%M%S`
  #echo TIMESTAMP is $TIMESTAMP

  echo "Processing $f file: $TIMESTAMP"

  convert -pointsize 18 -stroke white -fill white \
      -strokewidth 1 -draw "text 750,575 \"$TIMESTAMP\"" "$f" "$f"

done

