echo "Uppgift 1, test 1"
echo

fail=false

./ovn1
if [ $? -eq 139 ]; then
    echo "[1/3] Fel: Programmet kraschade utan indata!"
    fail=true
else
  echo "[1/3] Ok: Programmet kraschade inte utan indata"
fi

output=$(./ovn1 Anna)
expected_output="Hej Anna!"

if [ $? -eq 0 ] ; then
  echo "[2/3] Ok: Programmet returnerade noll"
else
  echo "[2/3] Fel: Programmet returnerade inte noll"
  fail=true
fi

if [ "$output" == "$expected_output" ] ; then
  echo "[3/3] Ok: Korrekt text returnerad. Förväntat \"'$expected_output'\" fick \"$output\""
else
  echo "[3/3] Fel: Förväntat \"'$expected_output'\" men fick \"$output\""
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
