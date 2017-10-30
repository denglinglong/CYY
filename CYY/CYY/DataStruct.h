//dll基数据结构体

//公共数据块
struct Generic_Header //通用头块
{
	uint Magic_Number;//1魔术字； 固定标志，用来指示雷达数据文件
	ushort Major_Version;//2主版本号
	ushort Minor_Version;//3次版本号
	uint Generic_Type;//4文件类型；1-基数据文件；2-气象产品文件；3-谱数据文件
	uint Product_Type;//5产品类型；文件为1时此字段无效
	uchar Reserved[16];//6保留字段
};

struct Site_Config//站点配置
{
	uchar Site_Code[8];//1站号；站号具有唯一性，用来区别不同的雷达站，如Z9010
	uchar Site_Name[32];//2站点名称；站点名称，如BeiJing
	float Latitude;//3纬度；雷达站天线所在位置纬度
	float Longitude;//4经度；雷达站天线所在位置经度
	uint Antenna_Height;//5天线高度；
	uint Ground_height;//6地面高度
	float Frequency;//7工作频率
	float Beam_Width_Hori;//8水平波束宽度
	float Beam_Width_Vert;//9垂直波束宽度
	uint RDA_Version;//10RDA版本号
	ushort Radar_Type;//11雷达类型；1-SA;2-SB;3-SC;33-CA;34-CB;35-CC;36-CCJ;37-CD;65-XA;66-KA;67-W
	float Transmitter_peak_power;//12发射机峰值功率
	float Antenna_gain;//13天线增益
	float Total_loss;//14收发总损耗
	float Receiver_gain;//15接受机增益
	float First_side;//16第一旁辦
	float Wavelength;//17发射信号波长
	float Receiver_linear_dynamic_range;//18接收机线性动态范围
	float Receiver_sensitivity;//19接收机灵敏度
	float Bandwidth;//20发射波形带宽
	ushort Maximum_detectable_range;//21最多探测距离
	ushort Distance_solution;//22距离分辨力
	uchar reserved[14];//23保留字段

};

struct Task_Config//任务配置
{
	uchar Task_Name[32];//1任务名称
	uchar Task_Description[128];//2任务描述
	uint Polarizaton_Type;//3极化方式
	uint Scan_Type;//4扫描任务类型
	uint Pulse_Width_1;//5脉冲宽度1
	uint Scan_Start_Time;//6扫描开始时间
	uint Cut_Number;//7扫描层次
	float Horizontal_Noise;//8水平通道噪声
	float Vertical_Noise;//9垂直通道噪声
	float Horizontal_Calibration;//10水平通道标定值
	float Vertical_Calibration;//11垂直通道标定值
	float Horizontal_Noise_Temperature;//12水平通道噪声温度
	float Vertical_Noise_Temperature;//13垂直通道噪声温度
	float ZDR_Calibration;//14ZDR标定偏差
	float PHIDP_Calibration;//15差分相移标定偏差
	float LDR_Calibration;//16系统LDR标定偏差
	uint Pulse_Width2;//17脉冲宽度2
	uint Pulse_Width3;//18脉冲宽度3
	uint Pulse_Width4;//19脉冲宽度4
	uchar Reserved[28];//20保留字段
};

struct Cut_Config//扫描配置
{
	uint Process_Mode;//1处理模式
	uint Wave_Form;//2波形类别
	float PRF_1;//3脉冲重复频率1
	float PRF_2;//4脉冲重复频率2
	uint Dealiasing_Mode;//5速度退模糊方法
	float Azimuth;//6方位角
	float Elevation;//7俯仰角
	float Start_Angle;//8起始角度
	float End_Angle;//9结束角度
	float Angular_Resolution;//10角度分辨率
	float Scan_Speed;//11扫描速度
	uint Log_Resolution;//12强度分辨率
	uint Doppler_Resolution;//13多普勒分辨率
	uint Maximum_Range1;//14最大距离1
	uint Maximum_Range2;//15最大距离2
	uint Start_Range;//16起始距离
	uint Sample1;//17采样个数1
	uint Sample2;//18采样个数2
	uint Phase_Mode;//19相位编码模式
	float Atmospheric_Loss;//20大气衰减
	float Nyquist_Speed;//21最大不模糊速度
	ulong Moments_Mask;//22数据类型掩码
	ulong Moments_Size_Mask;//23数据大小掩码
	uint Misc_Filter_Mask;//24滤波设置掩码
	float SQI_Threshold;//25SQI门限
	float SIG_Threshold;//26SIG门限
	float CSR_Threshold;//27CSR门限
	float LOG_Threshold;//28LOG门限
	float CPA_Threshold;//29CPA门限
	float PMI_Threshold;//30PMI门限
	float DPLOG_Threshold;//31DPLOG门限
	uchar Thresholds_r[4];//32阈值门限保留
	uint dBT_Mask;//33dBT质控掩码
	uint dBZ_Mask;//34DBZ质控掩码
	uint Velocity_Mask;//35速度质控掩码
	uint Spectrum_Width_Mask;//36谱宽质控掩码
	uint DP_Mask;//37偏振量质控掩码
	uchar Mask_Reserved[12];//38质控掩码保留位
	uint Scan_Sync;//39扫描同步标志
	uint Direction;//40天线运行方向
	ushort Ground_Clutter_Classifier_Type;//41地物杂波图类型
	ushort Ground_Clutter_Filte_Type;//42地物滤波类型
	ushort Ground_Clutter_Filter_Notch_Width;//43地物滤波宽度
	ushort Ground_Clutter_Filter_Window;//44滤波窗口类型
	ushort Pulse_width_combnation_mode;//45脉宽组合模式
	float Pulse_width1_starting_position;//46脉冲宽度1起始位置
	float Pulse_width2_starting_position;//47脉冲宽度2起始位置
	float Pulse_width3_starting_position;//48脉冲宽度3起始位置
	float Pulse_width4_starting_position;//49脉冲宽度4起始位置
	uchar Reserved[694];//50保留字段
};

struct Common_Block//公共数据块
{
	Generic_Header GenericHeader;//1通用头块
	Site_Config SiteConfig;//2站点配置
	Task_Config TaskConfig;//3任务配置
	Cut_Config CutConfig;//4扫描配置
};


//径向数据块
struct RADIAL_HEADER//径向头
{
	uint Radial_State;//1径向数据状态
	uint Spot_Blank;//2消隐标志
	uint Sequence_Number;//3序号
	uint Radial_Number;//4径向束
	uint Elevation_Number;//5仰角编号
	float Azimuth;//6方位角
	float Elevation;//7仰角
	uint iSeconds;//8秒
	uint Microseconds;//9微妙
	uint Length_of_data;//10数据长度
	uint Moment_Number;//11数据类别数量
	uint Seconds;//12秒
	ushort fft_point;//13FFT点数
	ushort Accumulation_of_power_spectrum;//14功率谱积累数
	uchar Reserved[12];//15保留字段
};

struct MOMENT_HEADER//径向数据头
{
	uint Data_Type;//1数据类型
	uint Scalel;//2比例
	uint Offset;//3偏移
	ushort Bin_length;//4库字节长度
	ushort Flags;//5标志
	uint Length;//6长度
	uchar Reserved[12];//7保留字段
};

struct MOMENT_DATA//径向数据
{

};

struct Radial//径向
{
	RADIAL_HEADER Radial_Header;//1径向头
	MOMENT_HEADER Moment_Header;//2径向数据头
	MOMENT_DATA Moment_Data;//3径向数据
};


