#!/opt/local/bin/bash

#LOGTIMESTAMP=`date +%Y%m%d-%H:%M:%S`

if [ -e "$1" ]
then

    LOGPREFIX=`basename "$1"`
    echo "****************************"
    echo -e "$LOGPREFIX:  Processing\n$LOGPREFIX:  $1\n$LOGPREFIX:    to a final home in\n$LOGPREFIX:  $2"

    DIR=`dirname "$1"`
    NEWDIR="$2"
    BASE=`basename "$1" | tr -d ' '`

    LAST_MODIFIED_EPOCH=`stat -f "%m" "$1"`
    TIMESTAMP=`date -r $LAST_MODIFIED_EPOCH +%Y%m%d-%H%M%S`

    NEWSUBDIR=`date -r $LAST_MODIFIED_EPOCH +%Y%m%d`
    mkdir -p "$NEWDIR/$NEWSUBDIR"
    BASEDIR="$NEWDIR"
    DIR="$NEWDIR/$NEWSUBDIR"

    #SLEEPTIME=$[ ( $RANDOM % 10 ) + 2 + ( $RANDOM % 10 ) ]
    SLEEPTIME=$[ ( $RANDOM % 3 ) + 1  ]

    echo "$LOGPREFIX:  Sleeping for $SLEEPTIME s"
    sleep $SLEEPTIME

    mv "$1" "$DIR/$BASE"
    rm "$1" &> /dev/null

    echo "$LOGPREFIX:  Timestamping $DIR/$BASE with $TIMESTAMP"

    CONVERT_COMMAND=/opt/local/bin/convert
    CONVERT_IN_FILE=$DIR/$BASE
    CONVERT_OUT_FILE=$DIR/$BASE
    TIMESTAMP_LOCATION_X=750
    TIMESTAMP_LOCATION_Y=575

    `$CONVERT_COMMAND -pointsize 18 -stroke white -fill white -strokewidth 1 \
        -draw "text $TIMESTAMP_LOCATION_X,$TIMESTAMP_LOCATION_Y '$TIMESTAMP'" \
    	    $CONVERT_IN_FILE $CONVERT_OUT_FILE`

    cp "$DIR/$BASE" "$DIR/$TIMESTAMP"-"$BASE"

    #echo "$LOGPREFIX:    Looking at vars:"
    #DIR=`dirname "$1"`
    #UPDIR=`dirname $DIR`
    #BASE=`basename "$DIR" | tr -d ' '`
    #UPBASE=`basename "$UPDIR" | tr -d ' '`
    #echo "$LOGPREFIX:      dir = $DIR"
    #echo "$LOGPREFIX:      updir = $UPDIR"
    #echo "$LOGPREFIX:      base = $BASE"
    #echo "$LOGPREFIX:      upbase = $UPBASE"

    ROOT_TERRITORY_NAME=`dirname "$1"`
    ROOT_TERRITORY_NAME=`basename $ROOT_TERRITORY_NAME`.jpg
    #echo "    ROOT=$ROOT_TERRITORY_NAME"

    echo -e "$LOGPREFIX:  Moving\n$LOGPREFIX:  $DIR/$BASE\n$LOGPREFIX:    to\n$LOGPREFIX:  $BASEDIR/$ROOT_TERRITORY_NAME"
    mv "$DIR/$BASE" "$BASEDIR/$ROOT_TERRITORY_NAME"
    rm "$DIR/$BASE" &> /dev/null
    rm "$1" &> /dev/null

    echo "****************************"

else

    echo "****************************"
    echo "  File $1 does not exist, nothing processed."
    echo "****************************"

fi
