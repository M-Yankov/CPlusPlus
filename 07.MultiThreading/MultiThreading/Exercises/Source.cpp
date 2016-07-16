#include <iostream>
#include <ctime>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable semaphore;

int calculatePrimeNumbers(unsigned int number);

void function(unsigned int number, int num)
{
	//spin lock
	std::cout << num << std::endl;
	
	// example output: num = 36;
	// 363839
	// 37959341
	// 40464748
	// the numbers is mixed - they are not in a sequence.
	
	// critical section.
	// to print response in sequence.
	mtx.lock();
	std::cout << calculatePrimeNumbers(number) << std::endl;
	mtx.unlock();

	// currently using this code we losing the effect from multi threading.
	// the better solution is to use multi threading for calculating and gather somewhere the response
	// and finally print whole response.
}

int calculatePrimeNumbers(unsigned int number)
{
	unsigned int countOfPrimeNumbers = 0;

	for (unsigned int i = 1; i <= number; i++)
	{
		if (i <= 2)
		{
			countOfPrimeNumbers++;
			continue;
		}

		int length = std::sqrt(i);
		int startNumber = 2;
		if (startNumber > length)
		{
			countOfPrimeNumbers++;
			continue;
		}

		for (unsigned int c = startNumber; c <= length; c++)
		{
			if (i % c == 0)
			{
				break;
			}

			if (c == length)
			{
				countOfPrimeNumbers++;
			}
		}
	}

	return countOfPrimeNumbers;
}

int main()
{
	std::clock_t startTime = std::clock();
	std::vector<std::thread> threads;

	for (int i = 0; i < 100; i++)
	{
		threads.push_back(std::thread(function, 100000, i));
	}

	int sizeThreads = threads.size();
	for (int i = 0; i < sizeThreads; i++)
	{
		// the program will be paused here.
		threads[i].join();
	}
	
	std::clock_t endTime = std::clock();
	
	double timeDifference = (endTime - startTime);
	double seconds = timeDifference / CLOCKS_PER_SEC;

	std::cout << "Program ends for " << seconds << " seconds." << std::endl;
	return 0;
}