class MedianFinder {
public:
 priority_queue<int> small;
 priority_queue<int,vector<int>,greater<int>> large;
 double median;

    MedianFinder() {
        median=INT_MIN;
    }
    int signum(int a, int b)
{
	if(a==b) return 0;
	else if(a>b) return 1;
	else return -1;
}
    void addNum(int element) {
        switch(signum(small.size(),large.size()))
	{
      case 0:
	  if(element>median)
	  {
		  large.push(element);
		  median=large.top();
	  }
	  else
	  {
		  small.push(element);
		  median=small.top();
	  }
	  break;
	  case 1:
	  if(element>median)
	  {
		  large.push(element);
		  median=(small.top()+large.top())/2.0;
	  }
	  else
	  {
		  large.push(small.top());
		  small.pop();
		  small.push(element);
		  median=(small.top()+large.top())/2.0;
	  }
	  break;
	  case -1:
	  if(element>median)
	  {
		  small.push(large.top());
		  large.pop();
		  large.push(element);
		   median=(small.top()+large.top())/2.0;
	  }
	  else
	  {
		  small.push(element);
		  median=(small.top()+large.top())/2.0;
	  }
	}
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */