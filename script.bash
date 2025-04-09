set -e

MODULE="module_09"
REPO_URL="https://github.com/AnnaFiona/42_cpp_Module_09"

git remote add $MODULE $REPO_URL;
git fetch $MODULE;

if git checkout -b $MODULE $MODULE/main; then
	echo "Checked out branch $MODULE/main.";
else
	git checkout -b $MODULE $MODULE/master;
	echo "Checked out branch $MODULE/master.";
fi

mkdir $MODULE;
#move everything except the new directory $MODULE into it
for item in *; do
    if [ "$item" != "$MODULE" ] && [ "$item" != "script.bash" ]; then
        mv "$item" "$MODULE/"
    fi
done

git add .;
git commit -m "Moved everything from $MODULE into subdirectory $MODULE";
git checkout main;
git merge $MODULE --allow-unrelated-histories
git push;
git remote rm $MODULE;
git branch -d $MODULE;