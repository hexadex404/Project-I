# Description
# Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
# Dữ liệu
# · Dòng 1: xâu P1
# · Dòng 2: xâu P2
# · Dòng 3: văn bản T
# Kết quả:
# · Ghi văn bản T sau khi thay thế
# Ví dụ
# Dữ liệu
# AI
# Artificial Intelligence
# Recently, AI is a key technology. AI enable efficient operations in many fields.
# Kết quả
# Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.

replace = input()
replace_with = input()
while True:
    try:
        text = input()
        text = text.replace(replace, replace_with)
        print(text)
    except EOFError:
        break