# Script runs CA for a number of parameters and presents the results on a big png image

for p in `seq 1 9`
do
	./random 33 33 0.$p > maps/p$p.initial
	for t in `seq 1 9`
	do
		for s in `seq 0 6`
		do
			echo $p $t $s
			cp maps/p$p.initial maps/current
			for i in `seq 1 5` 
			do
				./generate $t $s < maps/current > maps/tmp
				mv -f maps/tmp maps/current
				./draw maps/s$s'p'$p't'$t'i'$i.bmp < maps/current
			done
			convert label:"s = $s p = $p t = $t" maps/s$s'p'$p't'$t'i'{1,2,3,4,5}.bmp -append maps/s$s'p'$p't'$t.bmp 
		done
	done
done
convert maps/s{0,1,2,3,4,5,6}p{1,2,3,4,5,6,7,8,9}t{1,2,3,4,5,6,7,8,9}.bmp +append maps/report.png
rm -f maps/current
rm -f maps/*.bmp
