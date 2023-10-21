#include <stdio.h>

char *num_ones[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char *num_tens[10]={"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};
char *p2_1s[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fiveeen","Sixteen","Seventeen","Eighteen","Nineteen"};
	
main(){
	printf("The converter from number to words is ready...this is capable to convert numbers upto 15 digits\n");
	char num_str[25];//to get number as array of char...
	printf("Enter a number to convert: ");gets(num_str);
	char numbers[10]={'0','1','2','3','4','5','6','7','8','9'};
	int i,j,place_value_count=0,coma_count=0,len_num_str;
	long long number=0;
	for(i=0;1;i++){
		if(num_str[i]!='\0'){
			if(num_str[i]!=','){
				for(j=0;j<=9;j++){
					if(numbers[j]==num_str[i]){
						place_value_count+=1;
						number=number*10+j;
						break;
					}
				}
			}
			else if(num_str[i]=','){
				coma_count+=1;
			}
		}
		else{
			len_num_str=i;
			break;
		}
	}

	if(coma_count!=0){
		if(place_value_count<=5){
			goto label1;
		}
		else{
			if(num_str[len_num_str-7]==','){
				goto label1;
			}
			else if(num_str[len_num_str-7]!=','){
				goto label2;
			}
		}
	}
	else if(coma_count==0 && place_value_count<=5) goto label1;

	int choice;
	printf("\nThe number systems options available to convert the entered number are:-->\n\n1.Indian Number System\t\t2.International number System\n\n");
	printf("Choose a number system and enter the option number: ");
	scanf("%d",&choice);
	
	switch(choice){
		long long n_number,n_number2;
		case 1:
			label1:
			if(place_value_count<=9){
				num_indian(place_value_count,number);
			}
			
			else{//this will split the entered number at crore place value; evaluate the n.o of crores and remaining number seperately and then print them combined...
				n_number=number/10000000;//will have the value of the number before the crore place value...
				n_number2=number%10000000;//will have the value of number after the crore place value...
				num_indian(place_value_count,n_number);
				printf("Crore ");
				num_indian(place_value_count,n_number2);
			}
			break;
			
		case 2:
			label2:
			if(place_value_count<=9){
				num_international(place_value_count,number);
			}
			else{//this will split the entered number at billion place value;evaluata the n.o of billions,trilllions and the remaining number seperately and then print combined
				n_number=number/1000000000;//will have the value of the number after the millions i.e., billions and trillions... 
				n_number2=number%1000000000;//will have the value of the number before the billions i.e., millions,thousands...
				num_international2(place_value_count,n_number);num_international(place_value_count,n_number2);
			}
			break;
	}
}

//function..to convert the number according to Indian number system ..
num_indian(pvc,num){
	int place_value_dig,ones_place_value_dig,tens_place_value_dig;//place_value digit,next_place_value digit,tens_place_value digit
	while(pvc>0){
		switch(pvc){
			case 1://ones plce_value
				place_value_dig=num%10;/*this will have the place value dig*/tens_place_value_dig=(num%100)/10;/*this will have the tens place value digit*/
				if(place_value_dig==0 || tens_place_value_dig==1){//this condition says that to break if the place_value_dig is'0' or tens_place_value_dig is '1' because if tens_place_value_dig is '1' we have to print the 'teen' of the number
					break;
				}
				else{
					printf("%s ",num_ones[place_value_dig]);
					break;	
				}
			case 2://tens_place_value
				place_value_dig=(num%100)/10/*this will have the place value dig*/;ones_place_value_dig=num%10;/*this will have the ones_place_value_dig*/
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;	
				}
			case 3://hundred_place_value
				place_value_dig=(num%1000)/100;
				if(place_value_dig==0){
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;	
				}
			case 4://one_thousands_place_value
				place_value_dig=(num%10000)/1000;tens_place_value_dig=(num%100000)/10000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Thousand ",num_ones[place_value_dig]);
					break;	
				}
			case 5://ten_thousands_place_value
				place_value_dig=(num%100000)/10000;ones_place_value_dig=(num%10000)/1000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Thousand ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 6://one_lakh_place_value
				place_value_dig=(num%1000000)/100000;tens_place_value_dig=(num%10000000)/1000000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Lakh ",num_ones[place_value_dig]);
					break;	
				}
			case 7://ten_lakh_place
				place_value_dig=(num%10000000)/1000000;ones_place_value_dig=(num%1000000)/100000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Lakh ",p2_1s[ones_place_value_dig]);
					break;	
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 8:
				place_value_dig=(num%100000000)/10000000;tens_place_value_dig=(num%1000000000)/100000000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Crore ",num_ones[place_value_dig]);
					break;	
				}
			case 9:
				place_value_dig=(num%1000000000)/100000000;ones_place_value_dig=(num%100000000)/10000000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Crore ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;	
				}
		}
		pvc-=1;
	}
}

num_international(pvc,num){
	int place_value_dig,tens_place_value_dig,ones_place_value_dig;
	while(pvc>0){
		switch(pvc){
			case 1:
				place_value_dig=num%10;tens_place_value_dig=(num%100)/10;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s ",num_ones[place_value_dig]);
					break;
				}
			case 2:
				place_value_dig=(num%100)/10;ones_place_value_dig=num%10;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 3:
				place_value_dig=(num%1000)/100;
				if(place_value_dig==0){
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;	
				}
			case 4:
				place_value_dig=(num%10000)/1000;tens_place_value_dig=(num%100000)/10000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Thousand ",num_ones[place_value_dig]);
					break;	
				}
			case 5:
				place_value_dig=(num%100000)/10000;ones_place_value_dig=(num%10000)/1000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Thousand ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 6:
				place_value_dig=(num%1000000)/100000;tens_place_value_dig=(num%100000)/10000;ones_place_value_dig=(num%10000)/1000;
				if(place_value_dig==0){
					break;
				}
				
				else if(tens_place_value_dig==0 && ones_place_value_dig==0){
					printf("%s Hundred Thousands ",num_ones[place_value_dig]);
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;	
				}
			case 7:
				place_value_dig=(num%10000000)/1000000;tens_place_value_dig=(num%100000000)/10000000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Millions ",num_ones[place_value_dig]);
					break;	
				}
			case 8:
				place_value_dig=(num%100000000)/10000000;ones_place_value_dig=(num%10000000)/1000000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Millions ",p2_1s[ones_place_value_dig]);
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;	
				}
			case 9:
				place_value_dig=(num%1000000000)/100000000;tens_place_value_dig=(num%100000000)/10000000;ones_place_value_dig=(num%10000000)/1000000;
				if(place_value_dig==0){
					break;
				}
				else if(tens_place_value_dig==0 && ones_place_value_dig==0){
					printf("%s Hundred Millions",num_ones[place_value_dig]);
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;	
				}
		}
		pvc-=1;
	}
}

num_international2(pvc,num){
	int place_value_dig,tens_place_value_dig,ones_place_value_dig;
	while(pvc>0){
		switch(pvc){
			case 1:
				place_value_dig=num%10;tens_place_value_dig=(num%100)/10;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Billions ",num_ones[place_value_dig]);
					break;
				}
			case 2:
				place_value_dig=(num%100)/10;ones_place_value_dig=num%10;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Billions ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 3:
				place_value_dig=(num%1000)/100;tens_place_value_dig=(num%100)/10;ones_place_value_dig=num%10;
				if(place_value_dig==0){
					break;
				}
				else if(tens_place_value_dig==0 && ones_place_value_dig==0){
					printf("%s Hundred Billions ",num_ones[place_value_dig]);
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;
				}
			case 4:
				place_value_dig=(num%10000)/1000;tens_place_value_dig=(num%100000)/10000;
				if(place_value_dig==0 || tens_place_value_dig==1){
					break;
				}
				else{
					printf("%s Trillions ",num_ones[place_value_dig]);
					break;	
				}
			case 5:
				place_value_dig=(num%100000)/10000;ones_place_value_dig=(num%10000)/1000;
				if(place_value_dig==0){
					break;
				}
				else if(place_value_dig==1){
					printf("%s Trillions ",p2_1s[ones_place_value_dig]);
					break;
				}
				else{
					printf("%s ",num_tens[place_value_dig]);
					break;
				}
			case 6:
				place_value_dig=(num%1000000)/100000;tens_place_value_dig=(num%100000)/10000;ones_place_value_dig=(num%10000)/1000;
				if(place_value_dig==0){
					break;
				}
				
				else if(tens_place_value_dig==0 && ones_place_value_dig==0){
					printf("%s Hundred Trillions ",num_ones[place_value_dig]);
					break;
				}
				else{
					printf("%s Hundred ",num_ones[place_value_dig]);
					break;	
				}
		}
		pvc-=1;
	}
}
