#! /bin/sh

echo "now is morning yes or no?"
read YES_OR_NO
if [ "$YES_OR_NO" = "yes" ]; then
		echo "Good morning"
elif [ "$YES_OR_NO" = "no" ]; then
        echo "haha"
else
		echo "you print is errno"
		return 0
fi		

