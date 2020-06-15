using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;
using BookStore.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BookStore.Pages.BookDetail
{
    public class EditModel : PageModel
    {
        [BindProperty]
        public Book Book { get; set; }
        public List<Book> books { get; set; }
        public EditModel()
        {
            books = new List<Book>();
            FileStream fStream = new FileStream("wwwroot/Books.txt", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            while (!reader.EndOfStream)
            {
                var str = reader.ReadLine();
                books.Add(JsonSerializer.Deserialize<Book>(str));
            }
        }
        public void OnGet(string? id)
        { 
            Book = (from item in books
                   where item.Id == id
                   select item).FirstOrDefault();
        }
        public async Task<IActionResult> OnPost()
        {
            foreach(var item in books.ToList())
            {
                if (item.Id == Book.Id)
                {
                    books.Remove(item);
                    books.Add(Book);
                }
            }
            FileStream file = new FileStream("wwwroot/Books.txt", FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(file);
            foreach(var item in books.ToList())
            {
                var str = JsonSerializer.Serialize(item);
                writer.WriteLine(str);
            }
            writer.Close();
            return RedirectToPage("BookInfo");
        }
    }
}