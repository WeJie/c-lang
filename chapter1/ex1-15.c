# include <stdio.h>

float get_celsius(int fahr);
						
/*  打印华氏温度-摄氏温度对照表  */
int main() {
	int fahr;
	
	printf("============== Fahrenheit dregee and Celsius dregee ==============\n");
	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3.0d %6.1f\n", fahr, get_celsius(fahr));
}

/*  打印华氏温度-摄氏温度对照表  */
float get_celsius(int fahr) {
	return (5.0 / 9.0) * (fahr - 32);

}

