set -e

MODULE="module_08"
REPO_URL="https://github.com/AnnaFiona/42_cpp_Module_08"

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
mv ex0* $MODULE;

git add .;
git commit -m "Moved everything from $MODULE into subdirectory $MODULE";
git checkout main;
git merge $MODULE --allow-unrelated-histories
git push;
git remote rm $MODULE;
git branch -d $MODULE;