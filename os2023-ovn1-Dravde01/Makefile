# Övning 1
test-ovn1 : ovn1
	bash test/test_ovn1.sh

ovn1: ovn1.c
	gcc ovn1.c -o ovn1

clean-ovn1:
	rm -f ovn1

# Övning 2
test-ovn2 : ovn2
	bash test/test_ovn2.sh

ovn2: ovn2.c
	gcc ovn2.c -o ovn2

clean-ovn2:
	rm -f  ovn2

# Övning 3
test-ovn3 : ovn3
	bash test/test_ovn3.sh

test-ovn3-chars : ovn3-chars
	bash test/test_ovn3-chars.sh

ovn3: ovn3.c
	gcc ovn3.c -o ovn3

ovn3-chars: ovn3-chars.c
	gcc ovn3-chars.c -o ovn3-chars

clean-ovn3:
	rm -f ovn3 ovn3-chars

# Övning 4
test-ovn4 : ovn4
	bash test/test_ovn4.sh

test-ovn4-sort : ovn4-sort
	bash test/test_ovn4-sort.sh

ovn4: ovn4.c
	gcc ovn4.c -o ovn4

ovn4-sort: ovn4-sort.c
	gcc ovn4-sort.c -o ovn4-sort

clean-ovn4:
	rm -f ovn4 ovn4-sort

# För att rensa temporära filer
clean: clean-ovn1 clean-ovn2 clean-ovn3 clean-ovn4
