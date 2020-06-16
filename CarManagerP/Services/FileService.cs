using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarManagerP.Services
{
    public class FileService
    {
        public static List<string> ReadFromFile(string path)
        {
            List<string> lists = new List<string>();
            FileStream fStream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream, Encoding.Default);


            while (!reader.EndOfStream)
            {
                lists.Add(reader.ReadLine());
            }
            fStream.Close();
            reader.Close();
            return lists;
        }
        public static void AppendFile<T>(string path,T item)
        {
            FileStream fStream = new FileStream(path, FileMode.OpenOrCreate);
            StreamReader reader = new StreamReader(fStream,Encoding.Default);
            string contents = reader.ReadToEnd();
            reader.Close();
            fStream.Close();
            FileStream fhelp = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fhelp, Encoding.Default);
            writer.Write(contents);

            writer.WriteLine(item.ToString());
            
            writer.Close();

        }
        public static void RewriteFile<T>(string path, IEnumerable<T> lists)
        {
            FileStream fhelp = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fhelp, Encoding.Default);
            foreach (var item in lists)
            {
                writer.WriteLine(item.ToString());
            }
            writer.Close();
            fhelp.Close();
        }

    }
}
