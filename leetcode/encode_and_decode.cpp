public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        if(strs.size() == 0) return "";
        StringBuilder stringBuilder = new StringBuilder();
        StringBuilder sBLen = new StringBuilder();

        int index=0;
        for(String str : strs) {
            stringBuilder.append(str);
            sBLen.append(str.length());
            sBLen.append(',');
        }
        String unique = "AAAA";
        return sBLen.toString() + unique + stringBuilder.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        if(s.isEmpty()) return new ArrayList<>(0);
        int split = s.indexOf("AAAA");
        String[] splitString = new String[] {
                s.substring(0, split),
                s.substring(split+4)
        };
        String[] integers = splitString[0].split(",");

        List<String> result = new ArrayList<>();
        int index=0;
        for(String strLen : integers) {
            int len = Integer.parseInt(strLen);
            result.add(splitString[1].substring(index, index+len));
            index += len;
        }
            return result;
        }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));