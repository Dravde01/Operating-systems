echo "Uppgift 3, test 1"
echo

fail=false
numtests=8
currtest=1

./ovn3
if [ $? -eq 139 ]; then
    echo "[$currtest/$numtests] Fel: Programmet kraschade utan indata!"
    fail=true
else
  echo "[$currtest/$numtests] Ok: Programmet kraschade inte utan indata"
fi

currtest=$((currtest+1))

./ovn3
if [ $? -eq 1 ]; then
  echo "[$currtest/$numtests] Ok: Programmet gav output 1 utan indata." 
else
  echo "[$currtest/$numtests] Fel: Programmet gav inte output 1 utan indata!"
    fail=true
fi

currtest=$((currtest+1))

output=$(./ovn3 nonexisting.txt)
code=$?

if [ $code -eq 2 ]; then
    echo "[$currtest/$numtests] Ok: Programmet gav output $code då inputfilen saknades."
else
    echo "[$currtest/$numtests] Fel: Programmet gav inte output 2 då inputfilen saknades utan $code!"
    fail=true
fi

currtest=$((currtest+1))

output=$(./ovn3 lorem.txt)
code=$?

if [ $code -eq 0 ]; then
    echo "[$currtest/$numtests] Ok: Programmet gav output $code då inputfilen finns."
else
    echo "[$currtest/$numtests] Fel: Programmet gav inte output 0 då inputfilen existerar utan $code!"
    fail=true
fi

currtest=$((currtest+1))


touch empty.txt
output=$(./ovn3 empty.txt)
code=$?
expected_output="Antal tecken 0"
rm empty.txt

if [ "$output" == "$expected_output" ] ; then
  echo "[$currtest/$numtests] Ok: Korrekt text returnerad med tom fil. Förväntat \"$expected_output\" fick \"$output\"."
else
  echo "[$currtest/$numtests] Fel: Med tom fil. Förväntat \"$expected_output\" men fick \"$output\"."
  fail=true
fi

currtest=$((currtest+1))

awk -v seed=$RANDOM 'BEGIN {srand(seed);for (i = 0; i < 10000; i++){n = int(rand()*127); printf "%c", n}}' > test.txt
output=$(./ovn3 test.txt)
code=$?
expected_output="Antal tecken $(cat test.txt | tr -d '\n\t\r ' |wc -c)"
rm test.txt

if [ "$output" == "$expected_output" ] ; then
  echo "[$currtest/$numtests] Ok: Korrekt text returnerad med random text. Förväntat \"$expected_output\" fick \"$output\"."
else
  echo "[$currtest/$numtests] Fel: Med random text. Förväntat \"$expected_output\" men fick \"$output\"."
  fail=true
fi

currtest=$((currtest+1))

output=$(./ovn3 lorem.txt)
code=$?
expected_output="Antal tecken $(cat lorem.txt | tr -d '\n\t\r ' |wc -c)"

if [ "$output" == "$expected_output" ] ; then
  echo "[$currtest/$numtests] Ok: Korrekt text returnerad. Förväntat \"$expected_output\" fick \"$output\"."
else
  echo "[$currtest/$numtests] Fel: Förväntat \"$expected_output\" men fick \"$output\"."
  fail=true
fi

currtest=$((currtest+1))

if grep -q fclose "ovn3.c"; then
  echo "[$currtest/$numtests] Ok: Det verkar som om filpekaren har stängts."
else
  echo "[$currtest/$numtests] Fel: Det verkar som om filpekaren inte stängts!"
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
