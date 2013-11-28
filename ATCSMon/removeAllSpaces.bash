#!/bin/bash
#FILES=$1
for f in "$@"
do
  DIRNAME=`dirname "$f"`
  BASENAME=`basename "$f" | tr -d ' '`

  echo "Processing $f file: DIRNAME: $DIRNAME BASENAME: $BASENAME"

  mv "$f" "$DIRNAME"/"$BASENAME"


  # take action on each file. $f store current file name
  #cat "$f"
done

