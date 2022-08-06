function vals = orientationFromAcceleration(ax, ay, az)
    if az == 0
        az = 0.01;
    end    
    p = arctan(ay/az);
    e = arctan(ax/sqrt(ay^2 + az^2));
vals =  [p, e];