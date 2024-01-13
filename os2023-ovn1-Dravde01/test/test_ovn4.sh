echo "Uppgift 4, test 1"
echo

fail=false
numtests=5
currtest=1

./ovn4
if [ $? -eq 139 ]; then
    echo "[$currtest/$numtests] Fel: Programmet kraschade utan indata!"
    fail=true
else
  echo "[$currtest/$numtests] Ok: Programmet kraschade inte utan indata"
fi

currtest=$((currtest+1))

./ovn4
if [ $? -eq 1 ]; then
  echo "[$currtest/$numtests] Ok: Programmet gav output 1 utan indata." 
else
  echo "[$currtest/$numtests] Fel: Programmet gav inte output 1 utan indata!"
    fail=true
fi

currtest=$((currtest+1))

output=$(./ovn4 nonexisting.txt)
code=$?

if [ $code -eq 2 ]; then
    echo "[$currtest/$numtests] Ok: Programmet gav output $code då inputfilen saknades."
else
    echo "[$currtest/$numtests] Fel: Programmet gav inte output 2 då inputfilen saknades utan $code!"
    fail=true
fi

currtest=$((currtest+1))

touch empty.txt
output=$(./ovn4 empty.txt)
code=$?
expected_output=""
rm empty.txt

if [ "$output" == "$expected_output" ] ; then
  echo "[$currtest/$numtests] Ok: Rätt output med tom fil. Förväntat \"$expected_output\" fick \"$output\"."
else
  echo "[$currtest/$numtests] Fel: Fel output med tom fil. Förväntat \"$expected_output\" men fick \"$output\"."
  fail=true
fi

currtest=$((currtest+1))

output=$(./ovn4 lorem.txt)
code=$?
expected_output=$(awk -vFS="" '{for(i=1;i<=NF;i++){ if($i~/[a-zA-Z]/) { w[tolower($i)]++} } }END{for(i in w) print i,w[i]}' lorem.txt |sort)

if [ "$output" == "$expected_output" ] ; then
  echo "[$currtest/$numtests] Ok: Korrekt text returnerad. Förväntat \"$expected_output\" fick \"$output\"."
else
  echo "[$currtest/$numtests] Fel: Förväntat \"$expected_output\" men fick \"$output\"."
  fail=true
fi

echo

if [ "$fail" = true ]; then
  echo "Misslyckades med något av testen!"
  exit 1
else
  echo "Klarade alla test!"
  exit 0
fi
