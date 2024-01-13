echo "Uppgift 2, test 1"
echo

fail=false

./ovn2
if [ $? -eq 139 ]; then
    echo "[1/5] Fel: Programmet kraschade utan indata!"
    fail=true
else
  echo "[1/5] Ok: Programmet kraschade inte utan indata"
fi

./ovn2
if [ $? -eq 1 ]; then
  echo "[2/5] Ok: Programmet gav output 1 utan indata!" 
else
  echo "[2/5] Fel: Programmet gav inte output 1 utan indata!"
    fail=true
fi

indata=$(seq -s "aa " 11 111)
output=$(./ovn2 $indata)
code=$?
if [ $code -eq 2 ]; then
    echo "[3/5] Ok: Programmet gav output $code med fler än 100 outputs!"
else
    echo "[3/5] Fel: Programmet gav inte output 2 med fler än 100 outputs utan $?!"
    fail=true
fi

indata=$(seq -s "aa " 11 100)
output=$(./ovn2 $indata)
code=$?

if [ $code -eq 0 ]; then
    echo "[4/5] Ok: Programmet gav output $code med mindre än 100 outputs!"
else
    echo "[4/5] Fel: Programmet gav inte output 1 med mindre än 100 outputs utan $?!"
    fail=true
fi


indata=$(seq -s "aa " 11 110)
output=$(./ovn2 $indata)
code=$?
expected_output="Hej "$indata$"!"
echo $expected_output

if [ "$output" == "$expected_output" ] ; then
  echo "[5/5] Ok: Korrekt text returnerad. Förväntat \"'$expected_output'\" fick \"$output\""
else
  echo "[5/5] Fel: Förväntat \"'$expected_output'\" men fick \"$output\""
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
