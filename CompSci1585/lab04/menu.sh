print () {
    echo "v) View $file"
    echo "e) Edit $file"
    echo "c) Compile $file"
    echo "x) Execute $file"
    echo "q) Quit"
}

for file in *; do
    print

    read input

    case $input in
    v)
        less $file
        echo ""
        ;;
    e) 
        vim $file
        echo ""
        ;;
    c) 
        g++ $file
        echo ""
        ;;
    x)
        chmod +x $file
        ./$file
        echo""
        ;;
    q) 
        break
        echo ""
        ;;
    *)
        echo "Invalid input"
        echo ""
        echo "Skipping file!"
        echo ""
        ;;
    esac  
done