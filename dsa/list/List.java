public class List{

	private class Node{
		private Object obj;
		private Node next;

		public Node(){
			obj = null;
			next = null;
		}

		public Node(Object obj, Node Next){
			this.obj = obj;
			this.next = next;
		}

		public Node getNext(){
			return next;
		}

		public Object getObject(){
			return obj;
		}

		public void setObject(Object obj){
			this.obj = obj;
		}

		public void setNext(Node next){
			this.next = next;
		}

		public String toString(){
			return "("+obj+","+next+")";
		}
	}
	
	private Node head;
	int itemCount;

	List(){
		head = new Node();;
		itemCount = 0;
	}

	void add(Object obj){
		Node t = head;
		while(t.getNext()!=null){
			t = t.getNext();
		}
		t.setNext(new Node(obj,null));
		itemCount++;
	}

	boolean has(Object obj){
		Node t = head;
		while(t.getNext()!=null){
			t = t.getNext();
			if(t.getObject()==obj) return true;
		}
		return false;
	}

	public Object get(int index){
		Node t = head;
		int i = 0;
		while(t.getNext()!=null){
			t = t.getNext();
			if(i==index) return t.getObject();
			i++;
		}
		return null;
	}

	boolean update(Object oldObj, Object newObj){
		Node t = head;
		while(t.getNext()!=null){
			t = t.getNext();
			if(t.getObject()==oldObj){
				t.setObject(newObj);
				return true;
			}
		}
		return false;
	}

	boolean remove(Object obj){
		Node t = head, prev;
		while(t.getNext()!=null){
			prev = t;
			t = t.getNext();
			if(t.getObject()==obj){
				prev.setNext(t.getNext());
				t = null;
				itemCount--;
				return true;
			}
		}
		return false;
	}

	public String toString(){
		String str = "[";
		Node t = head;
		while(t.getNext()!=null){
			t = t.getNext();
			str += t.getObject();
			if(t.getNext()!=null) str += ", ";
		}
		str += "]";
		return str;
	}

	public static void main(String[] args){
		List list = new List();
		for(int i=1;i<=5;i++){
			System.out.println(list);
			list.add(i);
		}
		System.out.println(list);
		System.out.println("Has 5:"+list.has(5));
		for(int i=5;i>=1;i--){
			list.remove(i);
			System.out.println(list);
		}
		System.out.println("Has 5:"+list.has(5));
	}
}
