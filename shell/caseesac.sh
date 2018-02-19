#! /bin/bash

echo "now is morning yes or no ?"
read YES_NO
case "$YES_NO" in
YES|yes|Yes|y)
echo "good moning";;
[nN]*)
echo "goog evening";;
*)
echo "sorry you print is errno"
return 0;;
esac
return 1
