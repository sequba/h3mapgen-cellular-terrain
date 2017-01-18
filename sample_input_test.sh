# This script is intended to test CA on sample input file (with some superwhite and superblack square)

./randomize 0.6 < input_file > /tmp/dupa
for i in `seq 1 4` 
do
	./generate 7 < /tmp/dupa > /tmp/dupa2 
	cp -f /tmp/dupa2 /tmp/dupa
done
./draw maps/sample.bmp < /tmp/dupa

