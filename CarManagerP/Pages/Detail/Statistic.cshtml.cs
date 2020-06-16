using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using CarManagerP.Models;
using CarManagerP.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Data;
using FusionCharts.DataEngine;
using FusionCharts.Visualization;

namespace CarManagerP.Pages.Detail
{
    public class StatisticModel : PageModel
    {
        [BindProperty]
        public List<CarDetail> CarDetails { get; set; }
        [BindProperty]
        public string SearchOption { get; set; }
        [BindProperty]
        public List<CarStatic> sta { get; set; }

        
        public string ChartJson { get; internal set; }
        public StatisticModel()
        {
            const string path = @"..\车辆基本信息表.csv";
            CarDetails = new List<CarDetail>();
            var lists = FileService.ReadFromFile(path);
            CarDetails = InitializeService.InitializeCarDetail(lists);
            sta = new List<CarStatic>();
            Dictionary<string, CarStatic> dic = new Dictionary<string, CarStatic>();
            foreach (var item in CarDetails)
            {
                if (dic.ContainsKey(item.CarType))
                {
                    ++dic[item.CarType].Total;
                    if (item.State == "y")
                        ++dic[item.CarType].rent;
                    else
                        ++dic[item.CarType].free;
                }
                else
                {
                    int onrent = item.State == "y" ? 1 : 0;
                    dic.Add(item.CarType, new CarStatic
                    {
                        Type = item.CarType,
                        Total = 1,
                        rent = onrent,
                        free = 1 - onrent
                    });
                }
            }
            foreach (var item in dic)
            {
                sta.Add(item.Value);
            }
        }
        public void OnGet()
        {

        }
        public async Task OnPostAsync()
        {
                switch (SearchOption)
                {
                    case "TotalInfo":

                    break;
                    case "BarChart":

                    try
                    {
                        DataTable ChartData = new DataTable();
                        ChartData.Columns.Add("Programming Language", typeof(System.String));
                        ChartData.Columns.Add("Users", typeof(int));
                        foreach (var item in sta)
                        {
                            ChartData.Rows.Add(item.Type, item.Total);
                        }
                        // Create static source with this data table
                        StaticSource source = new StaticSource(ChartData);
                        // Create instance of DataModel class
                        DataModel model = new DataModel();
                        // Add DataSource to the DataModel
                        model.DataSources.Add(source);
                        // Instantiate Column Chart
                        Charts.ColumnChart column = new Charts.ColumnChart("first_chart");
                        // Set Chart's width and height
                        column.Width.Pixel(700);
                        column.Height.Pixel(400);
                        // Set DataModel instance as the data source of the chart
                        column.Data.Source = model;
                        // Set Chart Title
                        column.Caption.Text = "All type of the cars";
                        // Set chart sub title
                        column.SubCaption.Text = "2020.06";
                        // hide chart Legend
                        column.Legend.Show = false;
                        // set XAxis Text
                        column.XAxis.Text = "CarType";
                        // Set YAxis title
                        column.YAxis.Text = "Total";
                        // set chart theme
                        column.ThemeName = FusionChartsTheme.ThemeName.FUSION;
                        // set chart rendering json
                        ChartJson = column.Render();

                    }catch
                    {

                    }
                    break;
                    default:
                        break;
                }
            }
        public async Task OnPostTestAsync()
        {

        }
    }

}
