write_to_file()
{

     # initialize a local var
     local file="test.file"

     # check if file exists. this is not required as echo >> would 
     # would create it any way. but for this example I've added it for you
     # -f checks if a file exists. The ! operator negates the result
     if [ ! -f "$file" ] ; then
         # if not create the file
         touch "$file"
     fi

     # "open the file to edit" ... not required. echo will do

     # go in a while loop
     while true ; do
        # ask input from user. read will store the 
        # line buffered user input in the var $user_input
        # line buffered means that read returns if the user
        # presses return
        read user_input

        # until user types  ":q" ... using the == operator
        if [ "$user_input" == ":q" ] ; then
            return # return from function
        fi

        # write to the end of the file. if the file 
        # not already exists it will be created
        echo "$user_input" >> "$file"
     done
 }
 write_to_file