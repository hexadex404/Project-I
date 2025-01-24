# Description
# Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023), với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND. Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới, giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh. 

# Bậc	Biểu giá hiện hành	Phương án 5 bậc
#   	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
# 1	0-50 kWh	1.728	0-100 kWh	1.728
# 2	51-100 kWh	1.786	101-200 kWh	2.074
# 3	101-200 kWh	2.074	201-400 kWh	2.612
# 4	201-300 kWh	2.612	401-700 kWh	3.111
# 5	301-400 kWh	2.919	701 kWh trở lên	3.457
# 6  	401 kWh trở lên	3.015		
# (*) Giá chưa bao gồm thuế VAT

# Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.

# INPUT: là số kwh điện tiêu thụ của hộ (là số nguyên)
# OUTPUT: là chênh lệch giữa giá theo đề xuất và giá theo mô hình bậc thang 6 mức đang được áp dụng.

# VAT sẽ được lấy là 10%, và kết quả in ra sẽ lấy tới 2 chữ số thập phân

# EXAMPLE 
# INPUT
# 540
# OUTPUT
# -22176.00


# INPUT
# 70
# OUTPUT
# -1276.00

usage = int(input())
old = 0
new = 0

if usage <= 50:
    old = usage * 1.728
    old = new
elif usage <= 100:
    old = 50 * 1.728 + (usage - 50) * 1.786
    new = usage * 1.728
elif usage <= 200:
    old = 50 * 1.728 + 50 * 1.786 + (usage - 100) * 2.074
    new = 100 * 1.728 + (usage - 100) * 2.074
elif usage <= 300:
    old = 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + (usage - 200) * 2.612
    new = 100 * 1.728 + 100 * 2.074 + (usage - 200) * 2.612
elif usage <= 400:
    old = 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + 100 * 2.612 + (usage - 300) * 2.919
    new = 100 * 1.728 + 100 * 2.074 + (usage - 200) * 2.612 
elif usage <= 700:
    old = 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + 100 * 2.612 + 100 * 2.919 + (usage - 400) * 3.015
    new = 100 * 1.728 + 100 * 2.074 + 200 * 2.612 + (usage - 400) * 3.111
else:
    old = 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + 100 * 2.612 + 100 * 2.919 + (usage - 400) * 3.015
    new = 100 * 1.728 + 100 * 2.074 + 200 * 2.612 + 300 * 3.111 + (usage - 700) * 3.457 

old = old * 1.1
new = new * 1.1
print("{:.2f}".format((new - old)))


