# Script runs CA for a number of parameters and presents the results on a big png image

for p in `seq 1 5`
do
	../random 33 33 0.$p > maps/p$p.initial
	s='3'
	f='1'
	t=`../pick_threshold $s $f < maps/p$p.initial`
	echo $p
	cp maps/p$p.initial maps/current
	for i in `seq 1 6` 
	do
		../generate $t $s < maps/current > maps/tmp
		mv -f maps/tmp maps/current
		../draw maps/tmp.bmp < maps/current
		convert maps/tmp.bmp label:"p = 0.$p s = $s t = $t i = $i" -append maps/p$p'i'$i.bmp
	done
	convert maps/p$p'i'{1,2,3,4,5,6}.bmp -append maps/p$p.bmp 
done
convert maps/p{1,2,3,4,5}.bmp +append maps/report.png
rm -f maps/current
rm -f maps/*.bmp
