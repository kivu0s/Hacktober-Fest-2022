public class LinearSearch {
    public static void main(String[] args) {
        int[] nums = { 1, 15, 3, 7, 90 }; 
        System.out.println(search(nums, 122));
    }

    static String search(int[] arr, int target) {
        String ans;
        for (int index = 0; index <= arr.length; index++) {
            if (arr[index] == target) {
                ans = "Element found";
                return ans;
            }
        }
        ans = "Element not found";
        return ans;
    }

}
