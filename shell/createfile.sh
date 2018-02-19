#! /bin/bash

is_directory() #函数
{
     DIR_NAME=$1
	 if [ ! -d $DIR_NAME ];then #dirname的目录存在并且是个目录
			 return 1;
	 else
			 return 0;
     fi
} 
for DIR in "$@"; do
   if is_directory "$DIR" #调用函数并且传参
   then :
   else
		   echo "$DIR is not exist .creating now...."
		   mkdir $DIR > /dev/null 2>&1
		   if [ $? -ne 0 ]; then
		    echo "can not create directory $DIR"
			return 1;
	       fi
	fi
done
