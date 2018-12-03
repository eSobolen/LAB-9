#include<stdio.h> 
# include < stdlib.h> 
# include < string.h> 

# define TEST_MOD 0

# define MAX_CARS 10
# define STR_LEN 255
# define FREE_CAR_SLOT-1

# define CAR_REGNUMBER 0
# define CAR_MODEL 1
# define CAR_RUN 2
# define CAR_WORKER_NAME 3
# define CAR_PRICE 4



/ * run this program using the console pauser or add your own hech, system ("pause") or input loop * /
struct car_type
{
	int carRegNumber;
	char carModel [STR_LEN];		
	int carRun;
	char workerName [STR_LEN];
	price int ;
} carServise [MAX_CARS];

empty printAllCars ();
void printAllCarsFrom (struct car_type cars []);
void EditCarsAttribute (attribute N int, char satr [], structure car_type * car);
void clearCarServ ();
void clearCarIn (struct car_type cars []);
void log_testInfo ( char info []);
void deleteCar (car_type structure * car);
void log_testInfo ( char info []);
void sortingAllCars ();


saveArray int (structure car_type * a, size int file * f)
{
	fseek (f, 0, SEEK_SET);
	fwrite (a sizeof operator (car_type structure), size, f);
	returns 0 ;
}

int loadArray ( structure car_type * a, int size, file * f)
{
	fread (sizeof ( structure car_type), size, f);
	returns 0 ;
}


int main (int argc, char * argv [])
{
	int REGNUM, carRun, price, APR, output, exitCount, index ;
	Golets number [STR_LEN], workerName str. [STR_LEN], [STR_LEN];
	car_type structure buffer [MAX_CARS];
	char action = 0 ;
	
	* Fcars file;
	if (! (fcars = fopen ( " FILE_CARS.txt", " r + b " )))
	{
		printf ("cannot find file FILE_CARS \ n"); return ;
	}
	loadArray (carServise, MAX_CARS, fcars);
	fclose (fcars);


	clearCarIn (buffer);
	
	printAllCars ();

	while ( exit ! = 0 )
	{
		if (exitCount> 1000 )
		{
			exit = 0 ;
		}
		
		strcpy (str, " " );
		index = 0 ;
		clearCarIn (buffer);
		
		printf ( " 1 - Enter the car \ n " );
		printf functions ("2-Sort cars \ N » );
		printf ( " 3 - search for a car \ N » );
		printf ( " 4 - Change the car \ n " );
		printf ("5-Delete car \ n » );
		printf ( " 6 - print the car \ N » );
		printf ("7-exit \ n " );
		action = getch ();
		switch (action)
		{
			case ' 1 ' :
				printf functions ("Enter REGNUM car, car model, car mileage, name and price of working person \ n » );	
				scanf ( "% D% s% d% s% D " , & REGNUM, & carmodel, & carRun, & workerName, and the price);
				if (createCar (REGNUM, number, carRun, working name, price))
				{
					printf ("unable to create vehicle, garage full \ N » );
				}
			interval ;
			case ' 2 ' :
				sortingAllCars ();
			interval ;
			case ' 3 ' :
				printf ( " Search \ N " );
				printf ("1-regNum \ n " );
				printf ( " 2 - model car \ N " );
				printf functions ("3-start the car \ N » );
				printf ( " 4 - the name of the work \ N " );
				printf functions ("5-price \ n " );
				action = getch ();
				switch (action)
				{
					case ' 1 ' :
						atr = CAR_REGNUMBER;
					interval ;
					case ' 2 ' :
						atr = CAR_MODEL;
					interval ;
					case ' 3 ' :
						atr = CAR_RUN;
					interval ;
					case ' 4 ' :
						atr = CAR_WORKER_NAME;
					interval ;
					case ' 5 ' :
						atr = CAR_PRICE;
					interval ;
					by default :
						printf ("invalid attribute \ n " );
						printf functions ("case Search \ N " );
						atr = CAR_REGNUMBER;
					interval ;
				}
				printf ( " Enter the item \ N » );
				fflush (stdin);
				St. receives ();
				findCarsByAttribute street ( APR, buffer);
				printf ( "Cars with the rest of % s : \ n" , str);
				printAllCarsFrom (buffer);
			interval ;
			case ' 4 ' :
				printf ("enter the index \ n " );
				scanf ("% d", & index );
				if (carNum2Index (&index) = = - 1 )
				{
					printf ( " invalid index \ N " );
					interval ;
				}
				printf ( " Change: \ N » );
				printf ("1-regNum \ n " );
				printf ( " 2 - model car \ N " );
				printf functions ("3-start the car \ N » );
				printf ( " 4 - the name of the work \ N " );
				printf functions ("5-price \ n " );
				action = getch ();
				switch (action)
				{
					case ' 1 ' :
						atr = CAR_REGNUMBER;
					interval ;
					case ' 2 ' :
						atr = CAR_MODEL;
					interval ;
					case ' 3 ' :
						atr = CAR_RUN;
					interval ;
					case ' 4 ' :
						atr = CAR_WORKER_NAME;
					interval ;
					case ' 5 ' :
						atr = CAR_PRICE;
					interval ;
					by default :
						printf ("invalid attribute \ n " );
						printf functions ("case Search \ N " );
						atr = CAR_REGNUMBER;
					interval ;
				}
				printf ( " Enter the item \ N » );
				fflush (stdin);
				St. receives ();
				EditCarsAttribute (atr , str, & carServise [ index ]);
			interval ;
			case ' 5 ' :
				printf ("enter the index \ n " );
				scanf ("% d", & index );
				if (carNum2Index (&index) = = - 1 )
				{
					printf ( " invalid index \ N " );
					interval ;
				}
				printf ("Delete car with index = % d \ n", index );
				deleteCar (&carServise [ index ]);
			interval ;
			case ' 6 ' :
				printf functions ("Now we have these cars: \ N " );
				printAllCars ();
			interval ;
			case ' 7 ' :
				if (! (fcars = fopen ( " FILE_CARS.txt", " w + b " )))
				{
					printf ("cannot find file FILE_CARS \ n"); return ;
				}
				saveArray (carServise, MAX_CARS, fcars);
				fclose (fcars);
				returns 0 ;
			interval ;
			by default :
				exitCount ++;
				printf functions ("Wrong action \ n " );
			interval ;
		}
		printf ("\ n " );
	}
	
	if (! (fcars = fopen ( " FILE_CARS.txt", " w + b " )))
	{
		printf ("cannot find file FILE_CARS \ n"); return ;
	}
	saveArray (carServise, MAX_CARS, fcars);
	fclose (fcars);
	
	returns 0 ; 
}

int findFreeCarSlot ()
{
	int i;
	for (i =0 ; i < max_cars; I ++)
	{
		if (carServise [i]. carRegNumber == FREE_CAR_SLOT)
		{
			return i;	
		}
	}
	return-1 ;
}

int carNum2Index ( int * num)
{
	int i;
	if (*number < 0 | / * number> = MAX_CARS)
	{
		return-1 ;
	}
	for (i =0 ; i < max_cars; I ++)
	{

		log_testInfo ("Num " );
		if (carServise [i]. carRegNumber ! = FREE_CAR_SLOT)
		{
			* num = * num-1 ;	
			
			log_testInfo ("Num-- " );
		}
		if (*num < = 0 )
		{
			* num = i;
			log_testInfo ("FindNum » );
			return i;
		}
	}

	return-1 ;
}

void EditCarsAttribute (attribute N int, char satr [], structure car_type * car)
{
	int iatr = - 1 ;
	int i, j = 0 ;
	iatr = atoi (satr);	
	log_testInfo (satr);
	log_testInfo ("run car Edit  » );
	switch (attribute N)
	{
		case CAR_REGNUMBER:	
		
auto - > carRegNumber = IATR;
		interval ;
		case CAR_MODEL:	
			
			strcpy (car - > carModel, satr);
		interval ;
		car_run case:
		
car - > carRun = iatr;	
		interval ;
		case CAR_WORKER_NAME:	
			
			and strcpy ( auto - > workerName, satr);
		interval ;
		case CAR_PRICE:
		
			auto - > Price = IATR;
		interval ;
	}
}

findCarsByAttribute int (int attribute N, char satr [], structure car_type find [])
{
	int iatr = - 1 ;
	int i, j = 0 ;
	iatr = atoi (satr);	
	log_testInfo (satr);
	log_testInfo ("start car search » );
	for (i =0 ; i < max_cars; I ++)
	{
		switch (attribute N)
		{
			case CAR_REGNUMBER:	
			
				iatr = atoi (satr);
				if (carServise [i]. carRegNumber == iatr)
				{
					find [j] = carServise [i];
					J++ ;	
				}	
			interval ;
			case CAR_MODEL:	
			
				if (strncmp (satr, carServise [I]. carModel, STR_LEN) = = 0 )
				{
					find [j] = carServise [i];	
					J++ ;
				}	
			interval ;
			car_run case:
			
				if (carServise [i]. carRun == iatr)
				{
					find [j] = carServise [i];
					J++ ;
				}	
			interval ;
			case CAR_WORKER_NAME:	
				
				if (strncmp (satr, carServise [I]. workerName, STR_LEN) = = 0 )
				{
					log_testInfo ("We find the car car_worker_name » );
					find [j] = carServise [i];	
					J++ ;
				}
			interval ;
			case CAR_PRICE:
				
				iatr = atoi (satr);	
				if (carServise [i]. price = = IATR)
				{
					find [j] = carServise [i];	
					J++ ;
				}	
			interval ;
		}
	}
	return j;	
}

void sortingAllCars ()
{
	int I, j;
	struct car_type tmp;
	for (i =0 ; i < max_cars-1 ; i ++)
	{ 
		for (j = 0 ; j <MAX_CARS - I - 1 ; j ++)
		{  
			if (Servise [j]. RegNumber > Servise [J + 1 ]. carregnumber )
			{           
				tmp = carServise [j + 1 ];
				carServise [with J + 1] = carServise [j];
				carServise [j] = tmp; 
			}
		}
    }
}

void printCar (structure car_type * car)
{
	}

void printAllCars ()
{
	printAllCarsFrom (carservice);
}

void printAllCarsFrom ( struct car_type cars [])
{
	int i;
	printf ("\ n " );
	for (i = 0 ; i <MAX_CARS; i ++)
	{
		if (cars [i]. carRegNumber ! = FREE_CAR_SLOT || TEST_MOD)
		{
			printCar (&cars [i]);
		}
	}
	printf ("\ n " );
}

int createCar ( int carRegNumber, char carModel [], int carRun, char workerName [], price int )
{
	struct car_type * carServ;
	int indx = findFreeCarSlot ();
	if (indx = = - 1 )
	{
		log_testInfo ("ERROR: createCar - cant find free car slot \ n " );
		return 1 ;
	}
	printf ("% d", indx);
	carServise [INDX]. carRegNumber = carRegNumber;
	strcpy (carServise [indx]. carModel , carModel);
	carServise [INDX]. carRun = carRun;
	strcpy (carServise [indx]. workerName, workerName);
	carServise [INDX]. price = price;
	return 0 ;
}

void clearCarServ ()
{
	clearCarIn (carServise);
}

void clearCarIn ( struct car_type cars [])
{
	int i;
	for (i = 0 ; i <MAX_CARS; i ++)
	{
		deleteCar (& cars [i]);
	}
}

void deleteCar (car_type structure * car)
{	
car- > carRegNumber = FREE_CAR_SLOT;
	strcpy ( car - > carModel, " not car » );
car - > carRun = 0 ;
	strcpy ( car - > workerName , " does not have a worker » );
	car - > price = 0 ;
}

void log_testInfo ( char info [])
{
	if (TEST_MOD)
	{
		puts (info);
	}
}
