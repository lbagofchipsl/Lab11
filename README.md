# Lab11

Must follow standards cited here: https://github.com/olekaspt/LabStandards/blob/main/README.md

## Objective:
The objective of this Lab is to understand the basics for SCM

## Task
Make a repo on github (you need to make an account)
clone the repo to linux working env
Copy into the repo with some code (just grab any lab, or even my starter code).
Add the code to the repo
git add
git commit -a
git push NOTE for the push you will need to setup github token (classic)
Ok now we have a simulate developement ENV, and have show how to push to main branch. THis is not typical in industry.

git checkout -b "some cool name you come up with here"
modify any of the source file with any change
git add
git commit -a
git push --set-upstream origin "some cool name you come up with here"
OK now we have to go make a pull request on the website

goto your repo on github
Make pull request
No normally there is some protections on randos trashing your repo, but let's assume it passed

Close your merge reqeust
Almost done now let's mimic an active branch with mulitple cooks (NOTE the following portion can be skipped, as of 11-28-2023 it doesn't cause a merge)

git checkout -b "another cool name you come up with here"
Make a change to source file
Now using the web view, from main branch edit that source file with a different change (a comment change) but on the same line
git add .
git commit -a
git push
Make the merge reqeust and see we have a merges
Resolve merges (see the advice on merge request page)
Get your code to the repo
Submission
Send the repo link so we can see the merge requests.

## Alt Task
If you have already submitted to a repo and have done a pull request that has been merged. You can post the link the repo, your user name, and the pull request showing me that it was meged.

## Extra Credit
If you setup your repo to use actions to build and run the tests, you can obtain an extra 50 points to be used towards you labs. Use the actions file from Lab00. And follow steps done in lecture lab (it's recorded so you can obtain the recording from canvas).





