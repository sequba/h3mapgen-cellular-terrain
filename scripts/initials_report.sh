# Script runs CA for a number of parameters and presents the results on a big png image

for p in `seq 1 9`
do
	echo $p
	../draw maps/p$p.bmp < maps/p$p.initial
done
convert maps/p{1,2,3,4,5,6,7,8,9}.bmp +append maps/report.png
rm -f maps/current
rm -f maps/*.bmp
