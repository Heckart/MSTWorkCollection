# the purpose of the script is to return the name of the current user and the time in Unix time (seconds since January 1, 1970)

name=$(whoami)

echo "Your name is $name !"

time=$(date +%s)

echo "The current time is $date seconds"