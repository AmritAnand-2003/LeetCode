class Router {
    private Queue<Long> queue;
    private int size;
    private Map<Long, int[]> packets;
    private Map<Integer, List<Integer>> counts;

    public Router(int memoryLimit) {
        this.size = memoryLimit;
        this.queue = new LinkedList<>();
        this.counts = new HashMap<>();
        this.packets = new HashMap<>();
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        long key = encode(source, destination, timestamp);
        if(packets.containsKey(key))
            return false;
        if(packets.size() == this.size)
            forwardPacket();
        packets.put(key, new int[] {source, destination, timestamp});
        queue.offer(key);
        counts.putIfAbsent(destination, new ArrayList<>());
        counts.get(destination).add(timestamp);
        return true;
    }
    
    public int[] forwardPacket() {
        if(packets.isEmpty())
            return new int[] {};
        long key = queue.poll();
        int[] packet = packets.remove(key);
        if(packet == null)
            return new int[0];
        List<Integer> list = counts.get(packet[1]);
        list.remove(0);
        return packet;
    }
    
    public int getCount(int destination, int startTime, int endTime) {
        List<Integer> list = counts.get(destination);
        if(list == null || list.isEmpty())
            return 0;
        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);
        return right - left;
    }

    private long encode(final int source, final int destination, final int timestamp) {
        return ((long)source << 50 ) | ((long)destination << 30) | timestamp;
    }

    private int lowerBound(List<Integer> list, int target) {
        int low = 0, high = list.size();
        int res = high;
        while(low < high) {
            int mid = (low + high) >>> 1;
            if(list.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    private int upperBound(List<Integer> list, int target) {
        int low = 0, high = list.size();
        while(low < high) {
            int mid = (low + high) >>> 1;
            if(list.get(mid) <= target) {
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */