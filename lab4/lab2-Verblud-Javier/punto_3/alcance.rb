# encoding: utf-8

def execute()

    y = 222

    def Q(y)
        puts "Estático pues es y seguirá siendo"
    end

    def rewrite()
        y = 333
        Q(y)
    end
    
    rewrite()
    puts y

end
execute()