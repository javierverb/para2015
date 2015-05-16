def tail_rec(number, acc)
    if number == 0 then
        return 1/0
    else
        return tail_rec(number-1, acc)
    end
end

print("res=")
res = tail_rec(5, 0)
puts(res)