class Utility {
    public static <T extends Number> double getMidpoint(T[] arr) {
        if (arr.length % 2 == 0) {
            return (arr[arr.length / 2].doubleValue() + arr[(arr.length / 2) - 1].doubleValue()) / 2;
        } else {
            return arr[arr.length / 2].doubleValue();
        }
    }
    //else
    public static <T> T getMidpoint(T[] arr) {
        return arr[arr.length / 2];
    }

    public static <T> T getLast(T[] arr) {
        return arr[arr.length - 1];
    }

    public static <T> T getFirst(T[] arr) {
        return arr[0];
    }

    public static <T extends Number> double getAverage(T[] arr) {
        double total = 0;
        for (int i = 0; i < arr.length; i++) {
            total += arr[i].doubleValue();
        }
        return total / arr.length;
    }

    public static <T extends Comparable<T>> T getMin(T[] arr) {
        T min = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if (min.compareTo(arr[i]) > 0) { 
                min = arr[i];
            }
        }
        return min;
    }

    public static <T extends Comparable<T>> T getMax(T[] arr) {
        T max = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if (max.compareTo(arr[i]) < 0) { 
                max = arr[i];
            }
        }
        return max;
    }

    public static <T extends Number> int getSize(T[] arr) {
        return arr.length;
    }
}