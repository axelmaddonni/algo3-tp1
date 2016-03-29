for ((i=1;i<=$3;i++)); do
  java -jar $1 -exec $2 -test $i
done
