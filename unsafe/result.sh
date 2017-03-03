if [ "$WORKSPACE" == "" ]
then
echo "WORKSPACE is not set"
exit 1
fi

#for all dirs
for dir in `ls $WORKSPACE`
do
  #echo "checking " $dir
  python statistics.py $WORKSPACE/$dir/ 
done  
