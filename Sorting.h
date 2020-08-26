class Sorting {
	public:
		Sorting(int * myData, int size);
		void insertAlgorithm();
		void mergeAlgorithm();
		void quickSortAlgorithm();
		void printList();
		void insertTheItem(int * anArray, int start, int last);
		int getNumberComparisons();
		void mergeSort(int first, int last);
		void merge(int first, int middle, int last);
		void initiateQuickSort(int first, int last);
		void partition(int first, int last, int pivotIndex, int &nextPivotIndex);
	
	private:
		int * myArray;
		int size;
		int numberComparisons;
		
};