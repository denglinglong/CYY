//dll�����ݽṹ��

//�������ݿ�
struct Generic_Header //ͨ��ͷ��
{
	uint Magic_Number;//1ħ���֣� �̶���־������ָʾ�״������ļ�
	ushort Major_Version;//2���汾��
	ushort Minor_Version;//3�ΰ汾��
	uint Generic_Type;//4�ļ����ͣ�1-�������ļ���2-�����Ʒ�ļ���3-�������ļ�
	uint Product_Type;//5��Ʒ���ͣ��ļ�Ϊ1ʱ���ֶ���Ч
	uchar Reserved[16];//6�����ֶ�
};

struct Site_Config//վ������
{
	uchar Site_Code[8];//1վ�ţ�վ�ž���Ψһ�ԣ���������ͬ���״�վ����Z9010
	uchar Site_Name[32];//2վ�����ƣ�վ�����ƣ���BeiJing
	float Latitude;//3γ�ȣ��״�վ��������λ��γ��
	float Longitude;//4���ȣ��״�վ��������λ�þ���
	uint Antenna_Height;//5���߸߶ȣ�
	uint Ground_height;//6����߶�
	float Frequency;//7����Ƶ��
	float Beam_Width_Hori;//8ˮƽ�������
	float Beam_Width_Vert;//9��ֱ�������
	uint RDA_Version;//10RDA�汾��
	ushort Radar_Type;//11�״����ͣ�1-SA;2-SB;3-SC;33-CA;34-CB;35-CC;36-CCJ;37-CD;65-XA;66-KA;67-W
	float Transmitter_peak_power;//12�������ֵ����
	float Antenna_gain;//13��������
	float Total_loss;//14�շ������
	float Receiver_gain;//15���ܻ�����
	float First_side;//16��һ���k
	float Wavelength;//17�����źŲ���
	float Receiver_linear_dynamic_range;//18���ջ����Զ�̬��Χ
	float Receiver_sensitivity;//19���ջ�������
	float Bandwidth;//20���䲨�δ���
	ushort Maximum_detectable_range;//21���̽�����
	ushort Distance_solution;//22����ֱ���
	uchar reserved[14];//23�����ֶ�

};

struct Task_Config//��������
{
	uchar Task_Name[32];//1��������
	uchar Task_Description[128];//2��������
	uint Polarizaton_Type;//3������ʽ
	uint Scan_Type;//4ɨ����������
	uint Pulse_Width_1;//5������1
	uint Scan_Start_Time;//6ɨ�迪ʼʱ��
	uint Cut_Number;//7ɨ����
	float Horizontal_Noise;//8ˮƽͨ������
	float Vertical_Noise;//9��ֱͨ������
	float Horizontal_Calibration;//10ˮƽͨ���궨ֵ
	float Vertical_Calibration;//11��ֱͨ���궨ֵ
	float Horizontal_Noise_Temperature;//12ˮƽͨ�������¶�
	float Vertical_Noise_Temperature;//13��ֱͨ�������¶�
	float ZDR_Calibration;//14ZDR�궨ƫ��
	float PHIDP_Calibration;//15������Ʊ궨ƫ��
	float LDR_Calibration;//16ϵͳLDR�궨ƫ��
	uint Pulse_Width2;//17������2
	uint Pulse_Width3;//18������3
	uint Pulse_Width4;//19������4
	uchar Reserved[28];//20�����ֶ�
};

struct Cut_Config//ɨ������
{
	uint Process_Mode;//1����ģʽ
	uint Wave_Form;//2�������
	float PRF_1;//3�����ظ�Ƶ��1
	float PRF_2;//4�����ظ�Ƶ��2
	uint Dealiasing_Mode;//5�ٶ���ģ������
	float Azimuth;//6��λ��
	float Elevation;//7������
	float Start_Angle;//8��ʼ�Ƕ�
	float End_Angle;//9�����Ƕ�
	float Angular_Resolution;//10�Ƕȷֱ���
	float Scan_Speed;//11ɨ���ٶ�
	uint Log_Resolution;//12ǿ�ȷֱ���
	uint Doppler_Resolution;//13�����շֱ���
	uint Maximum_Range1;//14������1
	uint Maximum_Range2;//15������2
	uint Start_Range;//16��ʼ����
	uint Sample1;//17��������1
	uint Sample2;//18��������2
	uint Phase_Mode;//19��λ����ģʽ
	float Atmospheric_Loss;//20����˥��
	float Nyquist_Speed;//21���ģ���ٶ�
	ulong Moments_Mask;//22������������
	ulong Moments_Size_Mask;//23���ݴ�С����
	uint Misc_Filter_Mask;//24�˲���������
	float SQI_Threshold;//25SQI����
	float SIG_Threshold;//26SIG����
	float CSR_Threshold;//27CSR����
	float LOG_Threshold;//28LOG����
	float CPA_Threshold;//29CPA����
	float PMI_Threshold;//30PMI����
	float DPLOG_Threshold;//31DPLOG����
	uchar Thresholds_r[4];//32��ֵ���ޱ���
	uint dBT_Mask;//33dBT�ʿ�����
	uint dBZ_Mask;//34DBZ�ʿ�����
	uint Velocity_Mask;//35�ٶ��ʿ�����
	uint Spectrum_Width_Mask;//36�׿��ʿ�����
	uint DP_Mask;//37ƫ�����ʿ�����
	uchar Mask_Reserved[12];//38�ʿ����뱣��λ
	uint Scan_Sync;//39ɨ��ͬ����־
	uint Direction;//40�������з���
	ushort Ground_Clutter_Classifier_Type;//41�����Ӳ�ͼ����
	ushort Ground_Clutter_Filte_Type;//42�����˲�����
	ushort Ground_Clutter_Filter_Notch_Width;//43�����˲����
	ushort Ground_Clutter_Filter_Window;//44�˲���������
	ushort Pulse_width_combnation_mode;//45�������ģʽ
	float Pulse_width1_starting_position;//46������1��ʼλ��
	float Pulse_width2_starting_position;//47������2��ʼλ��
	float Pulse_width3_starting_position;//48������3��ʼλ��
	float Pulse_width4_starting_position;//49������4��ʼλ��
	uchar Reserved[694];//50�����ֶ�
};

struct Common_Block//�������ݿ�
{
	Generic_Header GenericHeader;//1ͨ��ͷ��
	Site_Config SiteConfig;//2վ������
	Task_Config TaskConfig;//3��������
	Cut_Config CutConfig;//4ɨ������
};


//�������ݿ�
struct RADIAL_HEADER//����ͷ
{
	uint Radial_State;//1��������״̬
	uint Spot_Blank;//2������־
	uint Sequence_Number;//3���
	uint Radial_Number;//4������
	uint Elevation_Number;//5���Ǳ��
	float Azimuth;//6��λ��
	float Elevation;//7����
	uint iSeconds;//8��
	uint Microseconds;//9΢��
	uint Length_of_data;//10���ݳ���
	uint Moment_Number;//11�����������
	uint Seconds;//12��
	ushort fft_point;//13FFT����
	ushort Accumulation_of_power_spectrum;//14�����׻�����
	uchar Reserved[12];//15�����ֶ�
};

struct MOMENT_HEADER//��������ͷ
{
	uint Data_Type;//1��������
	uint Scalel;//2����
	uint Offset;//3ƫ��
	ushort Bin_length;//4���ֽڳ���
	ushort Flags;//5��־
	uint Length;//6����
	uchar Reserved[12];//7�����ֶ�
};

struct MOMENT_DATA//��������
{

};

struct Radial//����
{
	RADIAL_HEADER Radial_Header;//1����ͷ
	MOMENT_HEADER Moment_Header;//2��������ͷ
	MOMENT_DATA Moment_Data;//3��������
};


