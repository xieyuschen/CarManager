#define COLUMNNAME_H
#ifdef COLUMNNAME_H
enum CarDetail {
	车辆类型编码 = 0,
	车辆类型名称,
	库存数量,

	车辆编号 = 10,
	车牌号,
	车辆类型编码,
	车辆名称,
	排挡方式,
	每日租金,
	出租状态,

	订单编号=20,
	身份证号,
	客人姓名,
	手机号码,
	租用车辆编号,
	取车时间,
	预约还车时间,
	押金,
	实际还车时间,
	应缴费用,
	实缴费用,

};
#endif // !COLUMNNAME_H
