#!/bin/bash


# estar na dev_mariano
git checkout dev_mariano


git add .
git commit -m "./merge"
git push origin dev_mariano


git pull origin dev_mariano
git push origin dev_mariano


git checkout master
git pull origin master
git push origin master

git checkout dev_rhuan
git pull origin dev_rhuan
git push origin dev_rhuan

git checkout dev_tk
git pull origin dev_tk
git push origin dev_tk

git checkout dev_joamila
git pull origin dev_joamila
git push origin dev_joamila


git checkout master


git merge dev_mariano
git push origin master

git merge dev_rhuan
git push origin master

git merge dev_tk
git push origin master

git merge dev_joamila
git push origin master


git checkout dev_mariano
git merge master
git push origin dev_mariano


# demais
<<COMMENT1
git checkout master
git pull origin master

git checkout dev_voce
git merge master
git push origin dev_voce
COMMENT1








