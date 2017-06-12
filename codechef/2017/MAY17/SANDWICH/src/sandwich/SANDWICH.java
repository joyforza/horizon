package sandwich;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Stack;
import java.util.Queue;
public class SANDWICH {
	public static void main(String[] args) {
		System.out.println("----------------------STACK--------------------");
		Stack<Integer> s = new Stack<Integer>();
		inputStack(s);
		outputStack(s);
		reverse1a(s);
		outputStack(s);

		System.out.println("----------------------QUEUE--------------------");
		Queue<Integer> q = new LinkedList<Integer>();
		inputQueue(q);
		outputQueue(q);
		sortQueue1(q);
		outputQueue(q);
	}

	static void inputStack(Stack<Integer> S)
	{
		System.out.print("Enter elements separated by space: ");
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			if(sc.hasNextInt())
			{
				int e = sc.nextInt();
				S.push(e);
			}
			else
			{
				try
				{
					sc.next();
				}
				catch(NoSuchElementException ex)
				{
					break;// end of input
				}
			}
		}
	}

	static void outputStack(Stack<Integer> S)
	{
		System.out.println(S);
	}

	public static void reverse1a(Stack<Integer> S)
	{
		//Reverse the order of elements on stack S using 2 additional stacks
		Stack<Integer> S1 = new Stack<Integer>();
		Stack<Integer> S2 = new Stack<Integer>();
		while(!S.isEmpty())
			S1.push(S.pop());

		while(!S1.isEmpty())
			S2.push(S1.pop());

		while(!S2.isEmpty())
			S.push(S2.pop());
	}



	public static void reverse1c(Stack<Integer> S)
	{
		//Reverse the order of elements on stack S using one additional stack and some additional non-array variables
		Stack<Integer> S1 = new Stack<Integer>();
		Integer topEl;
		int count = S.size()-1;
		while(count > 0)
		{
			topEl = S.pop();

			for(int i = 0; i < count; i++)
				S1.push(S.pop());

			S.push(topEl);

			while(!S1.isEmpty())
				S1.push(S.pop());

			count--;
		}
	}

	public static void sortStack(Stack<Integer> S)
	{
		//Put the elements on the stack S in ascending order using one additional stack and
		//some additional non-array variables


	}

	public static void transfer(Stack<Integer> S1, Stack<Integer> S2)
	{
		//Transfer elements from stack S1 to stack S2
		//so that the elements from S2 are in the same order as on S1
		//using no additional stack but only some additional non-array variables


	}

	static void inputQueue(Queue<Integer> Q)
	{
		System.out.print("Enter elements separated by space: ");
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			if(sc.hasNextInt())
			{
				int e = sc.nextInt();
				Q.offer(e);
			}
			else
			{
				try
				{
					sc.next();
				}
				catch(NoSuchElementException ex)
				{
					break;// end of input
				}
			}
		}
	}

	static void outputQueue(Queue<Integer> Q)
	{
		System.out.println(Q);
	}

	public static void sortQueue1(Queue<Integer> Q)
	{
		//Using two additional queue and some non-array variables, order all elements on a queue


	}

	public static void sortQueue2(Queue<Integer> Q)
	{
		//Using one additional queue and some non-array variables, order all elements on a queue


	}
}


//Define a stack in terms of a queue; that is, create a class
class StackQ<T> {
	Queue<T> pool = new LinkedList<T>();
	public void push(T el)
	{
		pool.offer(el);
	}
	public T pop()
	{
		T el;
		//write your code here
		//....................
                
                return el;
	}

	//write more your methods here
	//........................
}

//Define a queue in terms of a stack; that is, create a class
class QueueS<T> {
	Stack<T> pool = new Stack<T>();

	//write more your methods here
	//........................
}