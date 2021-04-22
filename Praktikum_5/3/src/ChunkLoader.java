import java.io.IOException;
import java.util.List;

public class ChunkLoader implements Runnable {
    private String chunkDataFilename;
    private Chunk chunk;

    public ChunkLoader(Chunk chunk, String chunkDataFilename) {
        this.chunk = chunk;
        this.chunkDataFilename = chunkDataFilename;
    }

    @Override
    public void run() {
        // Membaca file dengan nama chunkDataFilename
        // Gunakan class CSVReader.
        CSVReader reader = new CSVReader(chunkDataFilename, ",");
        reader.setSkipHeader(true);
        List<String[]> coor;
        try{
            coor = reader.read();
            int i = 0;
            while (i < coor.size()){
                chunk.addTree(new Position(Integer.valueOf(coor.get(i)[0]), Integer.valueOf(coor.get(i)[1])));
                i++;
            }
        } catch (IOException e){
            
        }
        // Contoh file chunkDataFilename:
        // x,y
        // 1,18
        // 10,8
        // 6,12
        // Untuk setiap x dan y, tambahkan tree ke Chunk
        // Jika ada IOException pada saat membaca reader, catch Exception
        // tidak ada tree yang ditambahkan pada Chunk (tidak dithrow lagi)
    }
}